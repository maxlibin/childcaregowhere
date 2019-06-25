open Emotion

let app = [%css [
  display `flex;
  flexDirection `column;
  height (`pct 100.);
]]

let title = [%css [
  fontSize (`px 48);
  maxWidth (`px 700);
  fontWeight 700;
  top (`px 100);
  left (`px 20);
  color (`hex "fff");
  lineHeight (`px 48);
]]

let content = [%css [
  position `fixed;
  zIndex 999;
  fontSize (`px 48);
  maxWidth (`px 700);
  fontWeight 700;
  top (`px 100);
  left (`px 20);
  color (`hex "fff");
  textShadow ~y:(`px 1) ~blur:(`px 1) (`rgba (0,0,0, 0.4));
  lineHeight (`px 48);
]]

let map = [%css [
  flex (`some (1., 1., (`pct 100.)));
  overflow `hidden;

  select ".leaflet-container" [
    height (`pct 100.);
    filters [(`hueRotate (`deg (-30.))); (`contrast (`pct 60.))];
  ];

  select ".leaflet-top.leaflet-left" [
    top (`px 90);
  ]
]]