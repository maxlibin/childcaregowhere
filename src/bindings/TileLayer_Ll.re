type center = (float, float);

[@bs.module "react-leaflet"] [@react.component]
external make: (~url: string, ~attribution: string) => React.element =
  "TileLayer";