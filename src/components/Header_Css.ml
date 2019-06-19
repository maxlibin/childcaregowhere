open Emotion

let header = [%css [
  width (`pct 100.);
  display `flex;
  backgroundColor (`rgba (255,255,255,0.2));
  minHeight (`px 40);
  borderBottom (`px 1) `solid (`rgba (0, 0, 0, 0.1));
  padding2 (`px 10) `zero;
  alignItems `center;
]]

let brand = [%css [
  fontSize (`px 18);
  fontWeight 700;
  textDecoration `none;
]]