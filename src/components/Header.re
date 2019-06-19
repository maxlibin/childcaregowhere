open Prelude;

module Css = Header_Css;

[@react.component]
let make = () =>
  <div className=Css.header>
    <div className=Global_css.container>
      <a href="/" className=Css.brand> Utils.brand->s </a>
    </div>
  </div>;