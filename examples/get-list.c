/*
 * This file is part of the libserialport project.
 *
 * Copyright (C) 2017 Justin Kim <justin.kim@collabora.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <libserialport.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char **argv)
{
  enum sp_return status;

  int i;
  struct sp_port **port_list = NULL;

  status = sp_list_ports (&port_list);

  if (status != SP_OK)
    {
      printf ("Failed to get port list (reason: %d)\n", status);
      return -1;
    }

  for (i = 0; port_list[i] != NULL; i++)
    {
      const struct sp_port *port = port_list[i];
      char *port_name = sp_get_port_name (port);
      printf ("Port Name: %s\n", port_name);
      free (port_name);
    }

  sp_free_port_list (port_list);

  return 0;
}
