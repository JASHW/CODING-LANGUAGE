// Intermediate JavaScript walkthrough
// Run with: node javascript/intermediate_walkthrough.js

"use strict";

class Task {
  #title;
  #completed;

  constructor(title) {
    if (typeof title !== "string" || title.trim() === "") {
      throw new TypeError("A task title must be a non-empty string.");
    }

    this.#title = title.trim();
    this.#completed = false;
  }

  get title() {
    return this.#title;
  }

  get completed() {
    return this.#completed;
  }

  complete() {
    this.#completed = true;
  }

  toJSON() {
    return { title: this.#title, completed: this.#completed };
  }
}

class TaskList {
  #tasks = [];

  add(title) {
    const task = new Task(title);
    this.#tasks.push(task);
    return task;
  }

  getAll() {
    // Return a copy so callers cannot change the internal array.
    return [...this.#tasks];
  }

  get pending() {
    return this.#tasks.filter((task) => !task.completed);
  }

  countCompleted() {
    return this.#tasks.reduce(
      (total, task) => total + Number(task.completed),
      0,
    );
  }
}

const tasks = new TaskList();
tasks.add("Read about JavaScript objects");
tasks.add("Practice array methods");
tasks.add("Build a small project").complete();

console.log("All tasks:");
console.log(tasks.getAll().map((task) => task.toJSON()));

console.log("Pending tasks:");
console.log(tasks.pending.map((task) => task.title));

console.log(`Completed: ${tasks.countCompleted()}`);

// Catch errors close to the operation that can fail.
try {
  tasks.add("   ");
} catch (error) {
  console.error(`Could not add task: ${error.message}`);
}

// async/await works with promises returned by asynchronous operations.
async function loadSummary(taskList) {
  const summary = await Promise.resolve({
    total: taskList.getAll().length,
    pending: taskList.pending.length,
  });

  return `Summary: ${summary.pending} of ${summary.total} tasks are pending.`;
}

loadSummary(tasks).then(console.log);
