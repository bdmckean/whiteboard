#!/usr/bin/env python3



islands = [[ 0 , 0 , 0 ,'i','i', 0 , 0 ,'i', 0 ],  
            [ 0 , 0 , 0 ,'i','i', 0 , 0 ,'i', 0 ], 
            [ 0 , 0 , 0 , 0 ,'i', 0 , 0 , 0 , 0 ], 
            [ 0 , 0 , 0 , 0 , 0 , 0 , 0 ,'i', 0 ], 
            [ 0 , 0 , 0 , 0 ,'i', 0 , 0 ,'i', 0 ], 
            [ 0 , 0 , 0 , 0 ,'i', 0 , 0 ,'i', 0 ], 
            [ 0 , 0 , 0 , 0 ,'i', 0 , 0 , 0 , 0 ], 
            [ 0 , 0 , 0 , 0 ,'i', 0 , 0 ,'i', 0 ] 
            ]


def find_islands(m, nr, nc):
    def map_island(r,c):
        print ("r=",r,"c=",c, m)
        if ( r > 0 and m[r-1][c] == 'i'):
            m[r-1][c] = island
            map_island(r-1,c)
        if ( c > 0 and m[r][c-1] == 'i'):
            m[r][c-1] = island
            map_island(r,c-1)
        if ( r < nr-1 and m[r+1][c] == 'i'):
            m[r+1][c] = island
            map_island(r+1,c)
        if ( c < nc-1 and m[r][c+1] == 'i'):
            m[r][c+1] = island
            map_island(r,c+1)

    island  = 0
    for r in range(nr):
        for c in range(nc):
            if m[r][c] == 'i':
                island += 1
                m[r][c] = island
                map_island(r,c)
    print (m)
    return island
           

            
i = find_islands(islands, 8 , 8)

print (i)


