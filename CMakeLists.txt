# Copyright (C) 2014 Jakub Lewandowski <jakub.lewandowski@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 2.8)
project(boost-mpl-book)

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

link_directories(${Boost_LIBRARY_DIRS})

add_subdirectory(ch2)
add_subdirectory(ch3)

enable_testing()
add_test(NAME chapter-2-test COMMAND ch2)
add_test(NAME chapter-3-test COMMAND ch3)
