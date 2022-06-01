import React, {useState}  from 'react';
import TodoList from './TodoList';

function App() {
  //this is called object destructuring 
   //? Read more here: https://www.youtube.com/watch?v=NIq3qLaHCIs
   const [tasks, setTasks] = useState(['Task #1', 'Task #2'])

  return (
    // tasks and todos here are called props
    //basically like an argument
    <>
      <TodoList tasks = {tasks}/> 
      <input type = "text"/>
      <button>Add a task</button>
      <button>Clear completed tasks</button>
      <div># of tasks uncompleted</div>
    </>
  );
}

export default App;
