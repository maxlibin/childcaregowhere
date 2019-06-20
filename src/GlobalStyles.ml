open Emotion;;

begin
  global "html, body" [
    fontFamily "B612 Mono, monospace";
    padding `zero;
    margin `zero;
    minHeight (`pct 100.);
    height (`pct 100.);
  ];

  global "#app" [
    minHeight (`pct 100.);
    height (`pct 100.);
  ]
end