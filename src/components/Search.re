open Prelude;

module Css = Search_Css;

[@react.component]
let make = () =>
  <form>
    <input className=Css.input />
  </form>;