import React from "react";

export default function Tasks({ task}){
    return (
        <div>
            <label>
                <input type = "checkbox" checked = {task.complete} />
                {task.name}
            </label>
            
        </div>
    )
}