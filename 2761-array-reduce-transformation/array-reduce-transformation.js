/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
   if (!nums.length)  return init;
   var val = init;

   for (const n of nums)
    val = fn(val, n);
    return val; 
};