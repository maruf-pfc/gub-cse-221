let arr = [2, 1, 4, 6, 3];

document.write(`Previous Output = ` + arr + "<br>");

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

let tmp = arr[1];
arr[1] = arr[3];
arr[3] = tmp;

document.write(`Current Output = ` + arr + "<br>");
document.write("<br>");