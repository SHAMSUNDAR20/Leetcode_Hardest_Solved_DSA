var createCounter = function(init) {
    let value = init;
    return {
        increment: function() {
            return ++value;
        },
        decrement: function() {
            return --value;
        },
        reset: function() {
            value = init;
            return value;
        }
    };
};