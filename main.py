import sys

def main(argc:int, argv:list[str]) -> None:
        # assert 1 : if a .mdd file is the fisrt argument and is accesible
        mdd_file = open(argv[1])
        # crashes if the file dosent exists
        
        if (argc >= 2 and argv[2].endswith('.css')):
                css_file = open(argv[2])
                
        

if __name__ == '__main__':
        
        argc = len(sys.argv)
        
        main(argc,sys.argv)