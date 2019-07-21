open Prelude;

module Css = App_Css;

type centers =
  | Loading
  | Failed(Js.Promise.error)
  | Loaded(array(ChildCareT.t));

type state = {
  centers,
  searchedCenters: option(array(ChildCareT.t)),
  search: string,
};

type action =
  | CentersLoaded(centers)
  | SearchUpdated(string)
  | SearchCentersLoaded(option(array(ChildCareT.t)));

let initialState = {centers: Loading, search: "", searchedCenters: None};

let reducer = (state, action) => {
  switch (action) {
  | CentersLoaded(centers) => {...state, centers}
  | SearchUpdated(search) => {...state, search}
  | SearchCentersLoaded(searchedCenters) => {...state, searchedCenters}
  };
};

[@react.component]
let make = () => {
  let ({centers, search, searchedCenters}, dispatch) =
    React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    Js.Promise.(
      Fetch.fetch("/data/childcare.json")
      |> then_(Fetch.Response.json)
      |> then_(json => {
           dispatch @@ CentersLoaded(Loaded(json->ChildCareT.result));
           resolve();
         })
      |> catch(err => {
           dispatch @@ CentersLoaded(Failed(err));
           resolve();
         })
      |> ignore
    );

    None;
  });

  React.useEffect1(
    () => {
      switch (centers, search) {
      | (Loading, _)
      | (Failed(_), _) => ()
      | (Loaded(center), _) when search != "" =>
        dispatch @@
        SearchCentersLoaded(
          Some(
            center->Array.keep(center =>
              Js.String.indexOf(search, center.centreName) >= 1
              || Js.String.indexOf(search, center.organisationDescription)
              >= 1
              || Js.String.indexOf(search, center.centreAddress) >= 1
            ),
          ),
        )
      | (Loaded(_), _) => dispatch @@ SearchCentersLoaded(None)
      };
      None;
    },
    [|search|],
  );

  <div className=Css.app>
    <Header />
    <div className=Css.content>
      <div className=Css.left>
        <div className=Css.title> Utils.title->s </div>
        <Search onChange={value => dispatch @@ SearchUpdated(value)} />
      </div>
      <div className=Css.right>
        <div className=Css.centers>
          {switch (centers) {
           | Loading => RR.null
           | Failed(_) => "Error loading data"->s
           | Loaded(centers) =>
             let centers =
               searchedCenters == None
                 ? centers : searchedCenters->Option.getWithDefault(centers);
             centers
             ->Array.map(center =>
                 <div
                   key={center.centreCode ++ center.tpCode}
                   className=Css.center>
                   <h3 className=Css.centerTitle> center.centreName->s </h3>
                   <div className=Css.centerContent>
                     <p> center.organisationDescription->s </p>
                     <p> center.centreAddress->s </p>
                     <p> center.centreWebsite->s </p>
                     <p> {center.centreContactNo->string_of_int->s} </p>
                   </div>
                 </div>
               )
             ->RR.array;
           }}
        </div>
      </div>
    </div>
    <div className=Css.map>
      <Map_Ll center=(1.385270, 103.851959) zoom=12>
        <TileLayer_Ll
          url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
          attribution="&copy; <a href=&quot;http://osm.org/copyright&quot;>OpenStreetMap</a> contributors"
        />
        <Marker_Ll position=(51.505, (-0.09))>
          <Popup_Ll>
            "A pretty CSS3 popup.<br />Easily customizable."->s
          </Popup_Ll>
        </Marker_Ll>
      </Map_Ll>
    </div>
  </div>;
};