// let arr = [2, 3, 1, 5, 4];

// user input
let arr = [];
let n = parseInt(prompt("Enter the number of elements: "));
for(let i  = 0; i < n; i++){
    let value = parseInt(prompt("Enter the element: "));
    arr.push(value);
}

function bubbleSort(arr) {
  for (var i = 0; i < arr.length; i++) {
    var flag = false;
    for (var j = 0; j < arr.length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        var tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
        flag = true;
      }
    }
    if (flag == false) break;
  }
}

document.write("Before Sorting: " + arr + "<br>");

bubbleSort(arr);

document.write("After Sorting: " + arr + "<br>");

// swap 2nd element with 4th element
let tmp = arr[1];
arr[1] = arr[3];
arr[3] = tmp;

document.write("After Swapping: " + arr + "<br>");