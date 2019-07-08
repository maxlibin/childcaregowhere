open Prelude;

module Css = App_Css;

type state =
  | Loading
  | Loaded(array(ChildCareT.t));

[@react.component]
let make = () => {
  let (childCareCenters, setChildCareCenters) = React.useState(_ => Loading);

  React.useEffect0(() => {
    Js.Promise.(
      Fetch.fetch("/data/childcare.json")
      |> then_(Fetch.Response.json)
      |> then_(json => {
           setChildCareCenters(_ => Loaded(json->ChildCareT.result));
           resolve();
         })
      |> ignore
    );

    None;
  });

  <div className=Css.app>
    <Header />
    <div className=Css.content>
      <div className=Css.left>
        <div className=Css.title> Utils.title->s </div>
        <Search />
      </div>
      <div className=Css.right>
        <div className=Css.centers>
          {
            switch (childCareCenters) {
            | Loading => RR.null
            | Loaded(centers) =>
              centers
              ->Array.map(center =>
                  <div
                    key={center.centreCode ++ center.tpCode}
                    className=Css.center>
                    <h3> center.centreName->s </h3>
                    <p> center.organisationDescription->s </p>
                  </div>
                )
              ->RR.array
            }
          }
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