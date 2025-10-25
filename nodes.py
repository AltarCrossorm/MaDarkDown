from dataclasses import dataclass
from typing import  Optional

@dataclass
class Node:
        """Classe de base pour tous les nœuds de l'AST."""
        value: str

@dataclass
class Text(Node):
        pass

@dataclass
class Heading(Node):
        level: int
        children: list[Node]

@dataclass
class Paragraph(Node):
        children: list[Node]

@dataclass
class Strong(Node):
        children: list[Node]

@dataclass
class Link(Node):
        url: str
        children: list[Node]
        
@dataclass
class Image(Node):
        url: str
        alt: str

@dataclass
class List(Node):
        ordered: bool
        children: list[Node]

@dataclass
class ListItem(Node):
        children: list[Node]

@dataclass
class CodeBlock(Node):
        lang: Optional[str]
        value: str

@dataclass
class Document(Node):
        """Entry point of the tokenizer"""
        children: list[Node]