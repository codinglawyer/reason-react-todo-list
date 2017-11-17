type item = {
  id: int,
  title: string,
  completed: bool
};

let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TodoItem");
let make = (~item, ~onToggle, children) => {
  ...component,
  render: (_) =>
    <div className="item" onClick=((_evt) => onToggle())>
      <input _type="checkboxz" checked=(Js.Boolean.to_js_boolean(item.completed)) />
      (str(item.title))
    </div>
};