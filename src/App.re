open Prelude;

module Css = App_Css;

[@react.component]
let make = () =>
  <div className=Css.app>
    <Header />
    <div className=Css.title> Utils.title->s </div>
    <div className=Css.content>
      <Map_Ll center=(51.505, (-0.09)) zoom=13>
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