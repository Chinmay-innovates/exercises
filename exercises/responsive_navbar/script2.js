document.addEventListener('DOMContentLoaded',function(){

   const setError = ( input,errorMessage)=>
   {
    const form =document.querySelector('.form');
    const  setError =(input,errorMessage);
    const inputAlert = formGroup.querySelector('.input-alert');
    inputAlert.innerText = errorMessage;
   } ;
   const setSucess = (input)=>
   {
    const formGroup = input.parentElement;
    formGroup.classList.remove('error');
    formGroup.classList.add('success');
   };
   const validEmail =(email) => {
   const re = /^(?=.{1,250}$)(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+")) @ ((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
   return re.test(String(email).toLocaleLowerCase());
};
    const validInput = (input,errorMessage) => {
    const value = input.value.trim();
    if(value === ""){
        setError(input , `${errorMessage}cannot be blank`);
        return false;
    } else if(input.name === 'email' && !validEmail(value)) {
        setError(input, 'Email is not valid')
        return false;
    }
    setSucess(input);
    return true;
};
const validPasswordMatch =() => {
    const password = form['password'].value.trim();
    const confirmPassword= form['confirm Password'].value.trim();
    
    if(password !== confirmPassword){
        setError(form['confirm Password'] , "Password do not match");
        return false;
    }
    setSucess(form['confirm Password']);
    return true;
};
const validatePasswordlength =(password) => {
    if(password.length < 8){
        setError(form ['password'], 'Password should be atleast 8 charecters ');
    }
    setSucess(form['password']);
    return true;
  };
   const resetForm =() => {
    // reset ater submisssion
    form.reset();
    // remove sucess class from all grps
   const formGroups = form.querySelectorAll('.form-group')
   formGroups.foreach((formGroup) => {
   formGroup.classList.remove('success');
   });
}
const inputs = form.querySelectorAll('.input');
inputs.forEach((input) => {
    input.addEventListener('input',function() {
        validateInput(input ,input.placeholder)
    });

    input.addEventListener('blur',function() {
        validateInput(input ,input.placeholder)
    });
});


 form.addEventListener('submit',function(event){
    event.preventDefault();
    const isValid =
    validateInput(form,['fullname'], 'Fullname')&&
    validateInput(form,['email'], 'Email')&&
    validatePasswordlength(form,['password'], value)&&
    validatePasswordMatch();

    if(isValid){
        alertconsole.log('Form submitted successfully!');
        resetForm();
    }
 });

});
