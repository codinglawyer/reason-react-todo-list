let component = ReasonReact.statelessComponent("Welcome");

let make = (children) => {
  ...component,
  render: (self) =>
    <div className="welcome">(ReasonReact.stringToElement("Welcome to the reason-react-boilerplate"))</div>
};
