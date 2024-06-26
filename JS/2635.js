/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
  /* const res = [];
    for(const [i, ele] of arr.entries()){
        res.push(fn(ele, i));
    }
    return res; */

  /* 
        reduce(callbackFn)
        reduce(callbackFn, initialValue)
            callbackFn
                accumulator - res
                current     - ele
                index       - i
            initialValue    - []
    */
  return arr.reduce((res, ele, i) => {
    res.push(fn(ele, i));
    return res;
  }, []);
};
