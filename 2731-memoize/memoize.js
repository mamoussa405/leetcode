function cmpArrays(arr1, arr2) {
    if (arr1.length !== arr2.length) return false;
    for (let i = 0; i < arr1.length; ++i)
        if (arr1[i] !== arr2[i]) return false;
    return true;
}

function inputSeen(prevArgs, args)
{
    for (let i = 0; i < prevArgs.length; ++i)
        if (cmpArrays(prevArgs[i].args, args)) return i;
    return -1;
}

/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    var save = null;
    var prevArgs = []; 
    return function(...args) {
        const idx = inputSeen(prevArgs, args);
        if (idx !== -1)
            return prevArgs[idx].save;
        save = fn(...args);
        prevArgs.push({args, save});
       return save;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */