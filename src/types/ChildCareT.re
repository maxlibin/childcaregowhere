type t = {
  tpCode: string,
  centreCode: string,
  centreName: string,
  organisationCode: string,
  organisationDescription: string,
}

module Decode = {
  let item = json =>
    Json.Decode.{
      tpCode: json |> field("tp_code", string),
      centreCode: json |> field("centre_code", string),
      centreName: json |> field("centre_name", string),
      organisationCode: json |> field("organisation_code", string),
      organisationDescription: json |> field("organisation_description", string),
    };
};

let result = data => Json.Decode.array(Decode.item, data);