#==============================
# Requirements
#==============================

cmake_minimum_required(VERSION 3.10)

#==============================
# Project Settings
#==============================

project("Gaia Behavior Tree" LANGUAGES CXX)

#==============================
# Inner Units
#==============================

# UDP Connection Library
add_subdirectory("BehaviorTree")

#==============================
# Outer Units
#==============================