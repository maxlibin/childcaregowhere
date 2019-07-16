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
  width (`calc(`sub, (`pct 100.), (`px 40)));
  marginLeft (`px 20);
  marginRight (`px 20);
  top (`px 100);
  height (`calc(`sub, (`vh 100.), (`px 100)));
  lineHeight (`px 48);
  display `flex;
]]

let left = [%css [
  color (`hex "fff");
  maxWidth (`pct 50.);
  fontSize (`px 48);
  fontWeight 700;
  textShadow ~y:(`px 1) ~blur:(`px 1) (`rgba (0,0,0, 0.4));
  paddingRight (`px 20);
]]

let right = [%css [
  paddingLeft (`px 20);
  flex (`some(1., 1., `auto));
  overflow `auto;
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
  width (`pct 100.);
  height (`pct 100.);
  display `block;
  zIndex 9;
  fontSize (`px 16);
]]

let center = [%css [
  backgroundColor (`rgba(255,255,255, 0.8));
  padding2 (`px 20) (`px 20);
  borderRadius (`px 3);
  marginBottom (`px 10);
  fontFamily "Helvetica, Arial, sans-serif";
  color (`hex "#333");
]]

let centerTitle = [%css [
  fontSize (`px 18);
  marginBottom (`px 18);
  marginTop `zero;
]]

let centerContent = [%css [
  fontSize (`px 16);

  select "p" [
    marginTop `zero;
    marginBottom (`px 16);
    lineHeight (`px 18);
  ]
]]