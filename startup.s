.cpu cortex-m4
.thumb
.word _reset
.thumb_func
_reset:
    B main
.size _reset, .-_reset