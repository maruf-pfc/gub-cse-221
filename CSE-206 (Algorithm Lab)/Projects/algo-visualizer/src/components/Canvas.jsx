import React from "react";

const MIN = 10;
const MAX = 100;
const SPEED = 1;

const generateRandomArray = (min, max) => {
  const array = [];
  for (let i = 0; i < 100; i++) {
    array.push(Math.floor(Math.random() * (max - min + 1)) + min);
  }
  return array;
};

const resetArray = () => {
  const array = generateRandomArray(MIN, MAX);
  console.log(array);
};

const play = () => {
  console.log("play");
};

const stop = () => {
  console.log("stop");
};

const changeSpeed = () => {
  console.log("change speed");
};

const Canvas = () => {
    
  return <div>Canvas</div>;
};

export default Canvas;
