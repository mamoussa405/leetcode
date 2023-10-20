/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    var save = null;
    var map = {}; 
    return function(...args) {
        const s = args.toString();
        if (s in map)
            return map[s];
        save = fn(...args);
        map[s] = save;
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