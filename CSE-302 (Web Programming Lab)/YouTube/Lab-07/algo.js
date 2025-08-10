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

function binarySearch(arr, target) {
  let l = 0;
  let r = arr.length - 1;

  while (l <= r) {
    let mid = Math.floor((l + r) / 2);
    if (arr[mid] === target) return mid;
    else if (arr[mid] < target) l = mid + 1;
    else r = mid - 1;
  }

  return -1;
}

module.exports = {
  bubbleSort,
  binarySearch,
};
