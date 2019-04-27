<!-- $theme: gaia -->

<!-- _class: lead -->
# object-oriented example

---

# What is function?

Hàm là một cái gì đó mà nó nhận vào một cái gì đó, sau đó xử lí và cuối cùng trả về một cái gì đó.

---

<!-- _class: lead -->
![](https://raw.githubusercontent.com/publicforall1/c-lang/master/Lecture/Images/function.gif)

---

<!-- _class: lead -->
![](https://raw.githubusercontent.com/publicforall1/c-lang/master/Lecture/Images/example_function0.gif)

---

<!-- _class: lead -->

```c
int main(void){
    // do something...
    return 0;
}
```

Ai gọi hàm `main` ?

---

```c
int main(void){
    printf("Hello, world!\n");
    return 0;
}
```

---

```c
#include <stdio.h>

int main(void){
    printf("Hello, world!\n");
    return 0;
}
```

---

<!-- _class: lead -->

# Let's compile it

---

```bash
gcc hello_world.c -o hello_world
```

```
./hello_world
Hello, world!
```
