import regex as re

from typing import Literal
from dataclasses import dataclass
from nodes import *


TokenType = Literal[
        "HEADING",
        "PARAGRAPH",
        "LINK",
        "IMAGE",
        "LISTITEM",
        "NEWLINE",
        "BOLD",
        "ITALIC",
        "UNDERLINE",
        "TEXT",
        "SPACE",
]

class Tokenizer:
        def __init__(self) -> None:
                pass
        
        def tokenize(self, input:str) -> list[Node]:
                token_list:list[Node] = []
                
                
                
                return token_list