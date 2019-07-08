type t = {
  tpCode: string,
  centreCode: string,
  centreName: string,
  organisationCode: string,
  organisationDescription: string,
  centreOperatingModel: string,
  centreContactNo: int,
  centreEmailAddress: string,
  centreAddress: string,
  postalCode: int,
  centreWebsite: string,
  infantVacancy: string,
  pgVacancy: string,
  n1Vacancy: string,
  n2Vacancy: string,
  k1Vacancy: string,
  k2Vacancy: string,
  foodOffered: string,
  secondLanguagesOffered: string,
  sparkCertified: string,
  weekdayFullDay: string,
  weekdayHalfdayAm: string,
  weekdayHalfdayPm: string,
  saturday: string,
  schemeType: string,
  extendedOperatingHours: string,
  provisionOfTransport: string,
  iccp: string,
  governmentSubsidy: string,
  gstRegisration: string,
  lastUpdated: string,
  remarks: string,
};

module Decode = {
  let item = json =>
    Json.Decode.{
      tpCode: json |> field("tp_code", string),
      centreCode: json |> field("centre_code", string),
      centreName: json |> field("centre_name", string),
      organisationCode: json |> field("organisation_code", string),
      organisationDescription:
        json |> field("organisation_description", string),
      centreOperatingModel: json |> field("centre_operating_model", string),
      centreContactNo: json |> field("centre_contact_no", int),
      centreEmailAddress: json |> field("centre_email_address", string),
      centreAddress: json |> field("centre_address", string),
      postalCode: json |> field("postal_code", int),
      centreWebsite: json |> field("centre_website", string),
      infantVacancy: json |> field("infant_vacancy", string),
      pgVacancy: json |> field("pg_vacancy", string),
      n1Vacancy: json |> field("n1_vacancy", string),
      n2Vacancy: json |> field("n2_vacancy", string),
      k1Vacancy: json |> field("k1_vacancy", string),
      k2Vacancy: json |> field("k2_vacancy", string),
      foodOffered: json |> field("food_offered", string),
      secondLanguagesOffered:
        json |> field("second_languages_offered", string),
      sparkCertified: json |> field("spark_certified", string),
      weekdayFullDay: json |> field("weekday_fullDay", string),
      weekdayHalfdayAm: json |> field("weekday_halfday_am", string),
      weekdayHalfdayPm: json |> field("weekday_halfday_pm", string),
      saturday: json |> field("saturday", string),
      schemeType: json |> field("scheme_type", string),
      extendedOperatingHours:
        json |> field("extended_operating_hours", string),
      provisionOfTransport: json |> field("provision_of_transport", string),
      iccp: json |> field("iccp", string),
      governmentSubsidy: json |> field("government_subsidy", string),
      gstRegisration: json |> field("gst_regisration", string),
      lastUpdated: json |> field("last_updated", string),
      remarks: json |> field("remarks", string),
    };
};

let result = data => Json.Decode.array(Decode.item, data);