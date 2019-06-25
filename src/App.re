open Prelude;

module Css = App_Css;

type state =
  | Loading
  | Loaded(array(ChildCareT.t));

[@react.component]
let make = () =>
{
  let (childCareCenters, setChildCareCenters) = React.useState(_ => Loading);

  React.useEffect0(() => {
    Js.Promise.(
      Fetch.fetch("/data/childcare.json")
      |> then_(Fetch.Response.json)
      |> then_(json => {
        setChildCareCenters(_ => Loaded(json -> ChildCareT.result));
        resolve();
      })
    );

    None;
  });

  Js.log(childCareCenters);
  <div className=Css.app>
    <Header />
    <div className=Css.title> Utils.title->s </div>
    <div className=Css.content>
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
  </div>};