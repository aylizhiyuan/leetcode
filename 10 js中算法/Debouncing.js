function debounce(fn,wait=50,immediate){
    let timer;
    return function(){
        if(immediate){
            fn.apply(this,arguments);
        }
        if(timer) clearTimeout(timer);
        timer = setTimeout(()=>{
            fn.apply(this,arguments);
        },wait);
    }
}

// 简单的防抖动函数
// 实际想绑定在 scroll 事件上的 handler
// function realFunc(){
//     console.log("Success");
// }

// // 采用了防抖动
// window.addEventListener('scroll',debounce(realFunc,500));
// // 没采用防抖动
// window.addEventListener('scroll',realFunc);