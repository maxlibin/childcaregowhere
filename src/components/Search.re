module Css = Search_Css;

[@react.component]
let make = (~onChange) =>
  <form>
    <input
      className=Css.input
      onChange={event => {
        let value = ReactEvent.Synthetic.target(event)##value;
        onChange(value);
      }}
    />
  </form>;