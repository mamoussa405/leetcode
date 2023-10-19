/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
   return {
       toBe(n) {
           if (n === val) return true
           throw Error("Not Equal")
       },
       notToBe(n) {
           if (n !== val) return true
           throw Error("Equal")
       }
   } 
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */