COMPILER = g++
COMPLIE = -c
VERSION = -std=c++11
CC = ${COMPILER} ${COMPLIE} ${VERSION}

BUILD_DIR=Build
SOURCE_DIR=src
JSON_DIR=${SOURCE_DIR}/Json
EXCEPTION_DIR=${SOURCE_DIR}/Exception

all:1.out

1.out: ${BUILD_DIR}/main.o ${BUILD_DIR}/JsonBiulder.o ${BUILD_DIR}/Array_Int.o ${BUILD_DIR}/Array_String.o ${BUILD_DIR}/Json_Array.o ${BUILD_DIR}/Json_Container.o ${BUILD_DIR}/Json_Data.o ${BUILD_DIR}/Json_Int.o ${BUILD_DIR}/Json_Object.o ${BUILD_DIR}/Json_String.o ${BUILD_DIR}/Duplicate_Key_Exception.o ${BUILD_DIR}/Invalid_ID_Exception.o ${BUILD_DIR}/Undefined_Type_Exception.o
	${COMPILER} ${VERSION} ${BUILD_DIR}/main.o ${BUILD_DIR}/JsonBiulder.o ${BUILD_DIR}/Array_Int.o ${BUILD_DIR}/Array_String.o ${BUILD_DIR}/Json_Array.o ${BUILD_DIR}/Json_Container.o ${BUILD_DIR}/Json_Data.o ${BUILD_DIR}/Json_Int.o ${BUILD_DIR}/Json_Object.o ${BUILD_DIR}/Json_String.o ${BUILD_DIR}/Duplicate_Key_Exception.o ${BUILD_DIR}/Invalid_ID_Exception.o ${BUILD_DIR}/Undefined_Type_Exception.o -o 1.out

${BUILD_DIR}/main.o: main.cpp JsonBuilder.hpp
	mkdir -p Build
	${CC} main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/JsonBiulder.o: JsonBuilder.hpp ${JSON_DIR}/JsonBuilder.cpp
	${CC} ${JSON_DIR}/JsonBuilder.cpp -o ${BUILD_DIR}/JsonBiulder.o

${BUILD_DIR}/Array_Int.o: ${JSON_DIR}/Array_Int.hpp ${JSON_DIR}/Array_Int.cpp
	${CC} ${JSON_DIR}/Array_Int.cpp -o ${BUILD_DIR}/Array_Int.o

${BUILD_DIR}/Array_String.o: ${JSON_DIR}/Array_String.hpp ${JSON_DIR}/Array_String.cpp
	${CC} ${JSON_DIR}/Array_String.cpp -o ${BUILD_DIR}/Array_String.o

${BUILD_DIR}/Json_Array.o: ${JSON_DIR}/Json_Array.hpp ${JSON_DIR}/Json_Array.cpp
	${CC} ${JSON_DIR}/Json_Array.cpp -o ${BUILD_DIR}/Json_Array.o

${BUILD_DIR}/Json_Container.o: ${JSON_DIR}/Json_Container.hpp ${JSON_DIR}/Json_Container.cpp
	${CC} ${JSON_DIR}/Json_Container.cpp -o ${BUILD_DIR}/Json_Container.o

${BUILD_DIR}/Json_Data.o: ${JSON_DIR}/Json_Data.hpp ${JSON_DIR}/Json_Data.cpp
	${CC} ${JSON_DIR}/Json_Data.cpp -o ${BUILD_DIR}/Json_Data.o

${BUILD_DIR}/Json_Int.o: ${JSON_DIR}/Json_Int.hpp ${JSON_DIR}/Json_Int.cpp
	${CC} ${JSON_DIR}/Json_Int.cpp -o ${BUILD_DIR}/Json_Int.o

${BUILD_DIR}/Json_Object.o: ${JSON_DIR}/Json_Object.hpp ${JSON_DIR}/Json_Object.cpp
	${CC} ${JSON_DIR}/Json_Object.cpp -o ${BUILD_DIR}/Json_Object.o

${BUILD_DIR}/Json_String.o: ${JSON_DIR}/Json_String.hpp ${JSON_DIR}/Json_String.cpp
	${CC} ${JSON_DIR}/Json_String.cpp -o ${BUILD_DIR}/Json_String.o

${BUILD_DIR}/Duplicate_Key_Exception.o: ${EXCEPTION_DIR}/Duplicate_Key_Exception.hpp ${EXCEPTION_DIR}/Duplicate_Key_Exception.cpp
	${CC} ${EXCEPTION_DIR}/Duplicate_Key_Exception.cpp -o ${BUILD_DIR}/Duplicate_Key_Exception.o

${BUILD_DIR}/Invalid_ID_Exception.o: ${EXCEPTION_DIR}/Invalid_ID_Exception.hpp ${EXCEPTION_DIR}/Invalid_ID_Exception.cpp
	${CC} ${EXCEPTION_DIR}/Invalid_ID_Exception.cpp -o ${BUILD_DIR}/Invalid_ID_Exception.o

${BUILD_DIR}/Undefined_Type_Exception.o: ${EXCEPTION_DIR}/Undefined_Type_Exception.hpp ${EXCEPTION_DIR}/Undefined_Type_Exception.cpp
	${CC} ${EXCEPTION_DIR}/Undefined_Type_Exception.cpp -o ${BUILD_DIR}/Undefined_Type_Exception.o

clean:
	rm 1.out
	rm ${BUILD_DIR}/*.o
	rmdir Build