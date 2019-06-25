type t = {
  tp_code: string,
}

module Decode = {
  let item = json =>
    Json.Decode.{
      tp_code: json |> field("tp_code", string),
    };
};

let result = data => Json.Decode.array(Decode.item, data);