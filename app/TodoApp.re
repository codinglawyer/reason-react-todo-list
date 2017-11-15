type item = {
  title: string,
  completed: bool
};

let str = ReasonReact.stringToElement;

module TodoItem = {
  let component =  ReasonReact.statelessComponent("TodoItem");
  let make = (~item, children) => {
    ...component,
    render: (self) =>
      <div className="item">
        <input
          _type="checkbox"
          checked=(Js.Boolean.to_js_boolean(item.completed))
        />
        (str(item.title))
      </div>
  };
};

type state = {
  items: list(item)
};

type action =
  | AddItem;

let component = ReasonReact.reducerComponent("TodoApp");
let newItem = () => {title: "Click a button", completed: false};

let make = (children) => {
  ...component,

  initialState: () => {
    items: [
      {
        title: "Write some things to do",
        completed: false
      }
    ]
  },

  reducer: (action, {items}) =>
  switch action {
  | AddItem => ReasonReact.Update({items: [newItem(), ...items]})
  },

  render: ({state: {items}, reduce}) => {
    let numItems = List.length(items);
    <div className="app">
      <div className="title"> (str("What to do")) </div>
      <button
        onClick=(reduce((_evt) => AddItem))
      >
        (str("Add something"))
      </button>
      <div className="items">
        (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((item) => <TodoItem item />, items)
          ))
        )
      </div>
      <div className="footer">
        (str(string_of_int(numItems) ++ " item"))
      </div>
    </div>
  }
};