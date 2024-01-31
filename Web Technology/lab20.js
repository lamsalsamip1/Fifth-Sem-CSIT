let fruits = ["Apple", "Banana", "Cherry"];
console.log(fruits);

let fruitColors = {
  Apple: "Red",
  Banana: "Yellow",
  Cherry: "Red",
};
console.log(fruitColors);

function printFruitColor(fruit) {
  let color = fruitColors[fruit];
  console.log(`The color of ${fruit} is ${color}.`);
}

fruits.forEach(printFruitColor);
