type t = {
  tpCode: string,
  centreCode: string,
  centreName: string,
  organisationCode: string,
  organisationDescription: string,
  centreOperatingModel: string,
  centreContactNo: int,
  centreEmailAddress: string,
}

module Decode = {
  let item = json =>
    Json.Decode.{
      tpCode: json |> field("tp_code", string),
      centreCode: json |> field("centre_code", string),
      centreName: json |> field("centre_name", string),
      organisationCode: json |> field("organisation_code", string),
      organisationDescription: json |> field("organisation_description", string),
      centreOperatingModel: json |> field("centre_operating_model", string),
      centreContactNo: json |> field("centre_contact_no", int),
      centreEmailAddress: json |> field("centre_email_address", string),
    };
};

let result = data => Json.Decode.array(Decode.item, data);