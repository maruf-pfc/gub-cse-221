let arr = [1, 4, 5, 6, 7];
let missing = [];

document.write(`Actual array = ` + arr + "<br>");

function binarySearch(arr, target){
    let l = 0;
    let r = arr.length - 1;

    while(l <= r){
        let mid = Math.floor((l + r) / 2);
        if(arr[mid] === target) return mid;
        else if(arr[mid] < target) l =  mid + 1;
        else r = mid - 1;
    }

    return -1;
}

let min = arr[0];
let max = arr[arr.length - 1];

for(let i = min; i <= max; i++){
    if(binarySearch(arr, i) === -1) {
        missing.push(i);
    }
}
document.write(`Missing Numbers are = ` + missing + "<br>");

for(let i = 0; i < missing.length; i++){
    arr.push(missing[i]);
}

function bubbleSort(arr){
    for(var i = 0; i < arr.length; i++){
    var flag = false;
        for(var j = 0; j<arr.length - i - 1; j++){  
            if(arr[j] > arr[j + 1]){
                var tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = true;
            }
        }
        if(flag == false)
        break;
    }
}
bubbleSort(arr);

document.write(`Final Array = ` + arr + "<br>");