type center = (float, float);

[@bs.module "react-leaflet"] [@react.component]
external make:
  (~center: center, ~zoom: int, ~children: React.element) => React.element =
  "Map";