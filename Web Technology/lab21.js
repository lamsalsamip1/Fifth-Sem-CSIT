// Create a new Date object
let date = new Date();

let dateString = date.toString();
console.log(dateString);

let utcString = date.toUTCString();
console.log(utcString);

let localeString = date.toLocaleString();
console.log(localeString);

let localeDateString = date.toLocaleDateString();
console.log(localeDateString);

let localeTimeString = date.toLocaleTimeString();
console.log(localeTimeString);
