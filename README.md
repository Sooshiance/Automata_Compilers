# Automata

There are three important areas in Computer Science field:

- **`Theory of Computation`**
- **`AI`**
- **`DSA`**

The most important theorem in the history of Automata is **`Halt of Turing machine`**. I wil explain it in **TM** part.

In all of the theoretical computer science scope we have 4 types of grammars and therefor we have 4 types of machines but,

The machines have different computation power and therefor we will list them based on powers from least one to most one.

Power of Automata in order:
- <a href="#fa">FA</a>
- <a href="#dpda">DPDA</a>
- <a href="#pda">PDA</a>
- <a href="#lba">LBA</a>
- <a href="#tm">TM</a>

There are two machines that missing here: 
- **Moore**
- **Mealy**

I will add them as soon as possible.

## FA

Before discussing about **`NFA`** & **`DFA`** let's see some theorem about them:

- Power of **DFA** & **NFA** are equals.
- For every **NFA** we have at least one **DFA** as equal.
- Every **grammar** can has many **FA** as equal, but any **FA** machine can produce only one **grammar**.
- Every **DFA** can have only one **Minimal DFA**.

The **FA** can define with 5 tuples:

- **`M = (Q, Σ, δ, q0, F)`**

I explain them quickly:
- **`Q`**: is the set of machines state.
- **`Σ`**: is alphabet of machine(They call `Tokens` in Compilers, in grammar known as `Terminals`).
- **`δ`**: is the transition function. In fact the `transition` function is the heart of every machines.
- **`q0`**: is the `initial state`.
- **`F`**: is the (set) `final state(s)`.

The **DFA** transition function:
- δ: Q * Σ ---> Q

The **NFA** transition function: 
- δ: Q * Σ ---> 2^Q

As you can see there is an uncertainty in **NFA** machines.

Now, I just implemented only **NFA** machine therefor you can modify it to gain **DFA**.

I will implement the **DFA** as soon as possible.

## DPDA

As you may know, the **DPDA** has less power compare to **NPDA**. Because **DPDA** can only computes just the **`odd-length`** string and **NPDA** can computes both.

Every **DPDA** can define with 7-tuples:

- **`M = (Q, Σ, Γ, q0, Z0, A, δ)`**

I explain them quickly:
- **`Q`**: is the set of machines state.
- **`Σ`**: is alphabet of machine(They call `Tokens` in Compilers, in grammar known as `Terminals`).
- **`Γ`**: is alphabet of stack.
- **`q0`**: is the `initial state`.
- **`Z0`**: is the `stack initial` symbol.
- **`A`**: where is the set of accepting, or final, states.
- **`δ`**: is the `transition` function.

About the **`PDA`** and **`DPDA`**:

- If **`L(A)`** is a language accepted by a **`PDA`** A, it can also be accepted by a **`DPDA`** if and only if there is a `single` computation from the initial configuration until an accepting one for all strings belonging to **`L(A)`**

- The power of **`PDA`** will change, If the **number** of tapes of stack increases.

## LBA

**I will add description for this model as soon as I add its program.**

## TM

**`Turing Machine`** is the most powerful computation model ever. This machine has a tape and a heads on that tape.

Read these theorems:

- This Head can move in `any` direction(Reciprocating motion).

- The tape has `no limits` on the numbers of `cells` and can `read` from it & `write` in it.

- You can `cut` the tape and put the two new part side by side `without losing` the machine's power. like this:

                                cutting the tape
      -------------------------------------------------------------------------------
                                           |                                       
      -------------------------------------------------------------------------------


---------------------------------------
|                                       ∞  <--- part 1
---------------------------------------
---------------------------------------
|                                       ∞  <--- part 2
---------------------------------------


This powerful machine can define with 7-tuples:

- **`M = (Q, Γ, b, Σ, δ, q0, F)`**

I explain them quickly:
- **`Γ`**: is `alphabet` of `tape`.
- **`Q`**: is the set of machines state.
- **`b`**: is the blank symbol (the only symbol allowed to occur on the tape infinitely often at any step during the computation).
- **`Σ`**: is alphabet of machine.
- **`δ`**: is the `transition` function.
- **`q0`**: is the `initial state`.
- **`F`**: is the set of `final` states.

So, If it is so powerful than can be changeable to other machines?
The answer is : **`YES`**

How to change **Turing machine** into: 
- **`FA`**: Set a limit on the number of cells of tape.
- **`PDA`**: Set a limit on the **Head** cursor tape that can move only and `only one` direction.
- **`LBA`**: As name suggest, you should set a limit on the number of cells **`but`**, the tape length is proportional to the input length.

**`Halt of Turing Machine problem`**:

Before we understanding the **Halt** problem, let's discuss about:

- **Computability theory**:The branch of theory of computation that studies which problems are computationally solvable using different model.

- **Decision problems**: A decision problem has only two possible outputs (yes or no) on any input. In computability theory and computational complexity theory, a decision problem is a problem that can be posed as a yes-no question of the input values.

- **program** & **algorithm**: In the Computer Science field **algorithm** is a procedure and it has start and end. **program** can start and never end like **Operating systems**(Operating system always wait for the next input).

And now what is the **Halt** problem?

Can we design a machine which if given a program can find out if that program will always halt or not halt on a particular input?

- In the general state The **Halt** problem will never stop in an specific state. You can set a limitation and solve it.

An example of **Halt** problem is in **Cryptographic** problems.
                            
                        g++ tm.cc -o tm
        ----------------------------------------------

        ----------------------------------------------


# Compilers
