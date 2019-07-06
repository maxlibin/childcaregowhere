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

let centers = [%css [
  position `fixed;
  right `zero;
  width (`pct 50.);
  height (`pct 100.);
  display `block;
  zIndex 9;
]]

let center = [%css [
  backgroundColor (`rgba(255,255,255, 0.8));
  padding2 (`px 20) (`px 20);
  borderRadius (`px 3);
  marginBottom (`px 10);
]]