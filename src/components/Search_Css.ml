open Emotion

let input = [%css [
  display `block;
  marginTop (`px 60);
  borderStyle `none;
  width (`pct 100.);
  height (`px 60);
  borderRadius (`px 3);
  backgroundColor (`rgba (255, 255, 255, 0.8));
  border (`px 1) `solid (`rgba (0,0,0, 0.4));
  outlineStyle `none;
  boxShadow ~y:(`px 1) ~blur:(`px 1) (`rgba (0,0,0, 0.2));
  padding2 (`px 10) (`px 20);
  fontSize (`px 16);
]]