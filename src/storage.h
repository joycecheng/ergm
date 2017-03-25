/*  File src/changestat.h in package ergm, part of the Statnet suite
 *  of packages for network analysis, http://statnet.org .
 *
 *  This software is distributed under the GPL-3 license.  It is free,
 *  open source, and has the attribution requirements (GPL Section 7) at
 *  http://statnet.org/attribution
 *
 *  Copyright 2003-2013 Statnet Commons
 */

/* Storage utilities */

#define ALLOC_STORAGE(nmemb, stored_type, store_into) stored_type *store_into = (stored_type *) (mtp->storage = calloc(nmemb, sizeof(stored_type)));
#define GET_STORAGE(stored_type, store_into) stored_type *store_into = (stored_type *) mtp->storage;

#define ALLOC_AUX_STORAGE(nmemb, stored_type, store_into) stored_type *store_into = (stored_type *) (mtp->aux_storage[(unsigned int) INPUT_PARAM[0]] = calloc(nmemb, sizeof(stored_type)));
#define GET_AUX_STORAGE(stored_type, store_into) stored_type *store_into = (stored_type *) mtp->aux_storage[(unsigned int) INPUT_PARAM[0]];
#define GET_AUX_STORAGE_NUM(stored_type, store_into, ind) stored_type *store_into = (stored_type *) mtp->aux_storage[(unsigned int) INPUT_PARAM[ind]];

/* Allocate a sociomatrix as auxiliary storage. */
#define ALLOC_AUX_SOCIOMATRIX(stored_type, store_into)			\
  /* Note: the following code first sets up a 2D array indexed from 0, then shifts all pointers by -1 so that sm[t][h] would work for vertex IDs. */ \
  ALLOC_AUX_STORAGE(N_TAILS, stored_type*, store_into);			\
  Dyad sm_size = BIPARTITE? N_TAILS*N_HEADS : DIRECTED ? N_NODES*N_NODES : N_NODES*(N_NODES+1)/2; /* For consistency, and possible future capabilities, include diagonal: */ \
  ALLOC_STORAGE(sm_size, stored_type, data); /* A stored_type* to data. */ \
  Dyad pos = 0;	  /* Start of the next row's data in the data vector. */ \
  for(Vertex t=0; t<N_TAILS; t++){                                      \
  /* First set up the pointer to the right location in the data vector, */ \
  if(BIPARTITE){							\
  store_into[t] = data+pos - N_TAILS; /* This is so that store_into[t][h=BIPARTITE] would address the 0th element of that row. */ \
  pos += N_HEADS;							\
  }else if(DIRECTED){							\
    store_into[t] = data+pos;						\
    pos += N_HEADS;							\
  }else{ /* Undirected. */						\
    store_into[t] = data+pos - t; /* tail <= head, so this is so that store_into[t][h=t] would address the 0th element of that row. */ \
    pos += N_HEADS-t+1; /* Each row has N_NODES - t + 1 elements (including diagonal). */ \
  }									\
  store_into[t]--; /* Now, shift the pointer by -1. */			\
  }									\
									\
  store_into--; /* Shift the pointer array by -1. */			\
  mtp->aux_storage[(unsigned int) INPUT_PARAM[0]] = store_into; /* This is needed to make sure the pointer array itself is updated. */

/* Free a sociomatrix in auxiliary storage. */
#define FREE_AUX_SOCIOMATRIX						\
  unsigned int myslot = (unsigned int) INPUT_PARAM[0];			\
  /* If we hadn't shifted the pointers by -1, this would not have been necessary. */ \
  GET_AUX_STORAGE(void*, sm);						\
  free(sm + 1);								\
  mtp->aux_storage[myslot] = NULL;					\
  /* nwp->storage was not shifted, so it'll be freed automatically. */	
