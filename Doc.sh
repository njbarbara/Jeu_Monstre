#!/usr/bin/env bash 
if [ -e "tmp.h" ] ; then 
    rm tmp.h
fi 


deb=$(cat *.h | head -n 6)

funct=$(cat *.h  | grep -E '^(void|int|float|char)' | tr ';' ';\n')

touch tmp.h 

echo "$deb" >> tmp.h
printf '\n' >> tmp.h

#correction=$(echo "$funct" | sed -E 's/\(/ ( /g' | sed -E 's/\)/ ) /g')

echo "$funct" | while read f ; do 
    if echo "$f" | grep -E '^(void)'; then 
        echo "/**
    \brief 
    \param
*/" >> tmp.h
    else 
        echo "/**
    \brief 
    \param
    \return
*/" >> tmp.h
    fi
    echo "$f" >> tmp.h
    printf '\n' >> tmp.h
done 


