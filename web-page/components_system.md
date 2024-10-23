```PHP

  <?php

    interface component{
        public function input($id, $class, $name, $type, $placeholder, $required);
        public function button($class, $type, $value);
        public function span($loopnum, $class, $text);
    }

    class globalView implements component{

        public function __construct(string $var = null) {
            $this->var = $var;
        }

        public function input($id, $class, $name, $type, $placeholder, $required){
            include 'input.php';
        }

        public function button($class, $type, $value){
            include 'button.php';
        }

        public function span($loopnum, $class, $text){
            $count = 0;
            if($count != $loopnum){
                include 'span.php';
                $count+=1;
                $this -> span($loopnum - 1, $class, $text);
            }
        }
    }

    $globalView = new globalView();

  ?>

```

```PHP

  <?php
    echo "
        <span 
            class='$class'>
            $text
        </span>
    ";
  ?>

```

```PHP

  <?php
    echo "
        <input 
            id='$id'
            class='$class'
            name='$name'
            type='$type' 
            placeholder='$placeholder'
            required='$required'
        />
    ";
  ?>

```

```PHP

  <?php
    echo "
        <input 
            class='$class' 
            type='$type' 
            value='$value' 
        />
    ";
  ?>

```

```PHP

  <?php $globalView -> span(5, "material-symbols-outlined", "star")?>

```
