//Bubble sort

fun ArrayList<Int>.bubbleSort()
 : ArrayList<Int>{
    var swap = true
    while(swap){
        swap = false
        for(i in 0 until this.indices.last){
            if(this[i] > this[i+1]){
                val temp = this[i]
                this[i] = this[i+1]
                this[i + 1] = temp
                
                swap = true
            }
        }
    }
    return this
}

fun main(args: Array<String>) {
    val list = arrayListOf(5,4,2,8,1)
        .bubbleSort()
    list.forEach{
        println(it)
    }
}
