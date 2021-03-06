open Emotion

let header = [%css [
  width (`pct 100.);
  display `flex;
  minHeight (`px 40);
  padding2 (`px 10) `zero;
  alignItems `center;
  position `fixed;
  zIndex 999;
]]

let brand = [%css [
  fontSize (`px 18);
  fontWeight 700;
  textDecoration `none;
  color (`hex "fffb00");
  textShadow ~y:(`px 1) ~blur:(`px 1) (`rgba (0,0,0, 0.4));
]]