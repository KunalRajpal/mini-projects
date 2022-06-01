import React, {useState, useRef}  from 'react';
import TodoList from './TodoList';
import uuidv4 from 'uuid/v4';

function App() {
  //this is called object destructuring 
  //? Read more here: https://www.youtube.com/watch?v=NIq3qLaHCIs
  const [tasks, setTasks] = useState([]);
  const taskNameRef = useRef();

  function handleAddTodo(e) {
    const name = taskNameRef.current.value; 
    if(name === '') return;
    setTasks (prevTasks => {
      return [...prevTasks, {id: 1, name: name, complete: false}]
    })
    taskNameRef.current.value = null;
  }

  return (
    // tasks and todos here are called props
    //basically like an argument
    <>
      <TodoList tasks = {tasks}/> 
      <input ref = {taskNameRef} type = "text"/>
      <button onClick={handleAddTodo }>Add a task</button>
      <button>Clear completed tasks</button>
      <div># of tasks uncompleted</div>
    </>
  );
}

export default App;
